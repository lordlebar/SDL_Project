// SDL_Test.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <stdio.h>
#include <vector>
#include <ctime>

void init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
}

SDL_Surface* load_surface_for(const std::string& path, SDL_Surface* window_surface_ptr) {

  if (!window_surface_ptr){
    std::cout << "No valid window surface passed as argument. Bad." << std::endl;
    return (nullptr);
  }

  int length = (int)path.length();
  char new_file_path[length];
  strcpy(new_file_path, path.c_str()); // we have successfully converted our string into an array of char.

  SDL_Surface* surf = SDL_ConvertSurface(IMG_Load(new_file_path), window_surface_ptr->format, 0);
  if (!surf){
    std::cout << "Error during creation of surface." << std::endl;
    return (nullptr);
  }

  return (surf);
}

animal::animal(const std::string &file_path, SDL_Surface *window_surface_ptr, bool horizontal_direction, bool vertical_direction)
    : window_surface_ptr_{window_surface_ptr}, horizontal_direction_{horizontal_direction}, vertical_direction_{vertical_direction}{
    
    image_ptr_ = load_surface_for(file_path, window_surface_ptr);
    if (image_ptr_ == nullptr)
        throw std::runtime_error("animal::animal(): " + std::string(SDL_GetError()));
    
    // Set random position of the animal
    posX_ = rand() % (frame_width - frame_boundary - image_ptr_->w) + frame_boundary;
    posY_ = rand() % (frame_height - frame_boundary - image_ptr_->h) + frame_boundary;
};

void animal::draw() const
{
    if (window_surface_ptr_ == nullptr || image_ptr_ == nullptr){
      std::cout << "pointers aren't ok, bro, do something";
      return;
    }

    //These two next lines are used to get rid of the PNG backgrounds
    Uint32 color_key = SDL_MapRGB(image_ptr_->format, 0, 0, 0);
    SDL_SetColorKey(image_ptr_, SDL_TRUE, color_key);
    SDL_Rect sheep_rect;
    sheep_rect.x = posX_;
    sheep_rect.y = posY_;

    SDL_BlitSurface(image_ptr_, nullptr, window_surface_ptr_, &sheep_rect);
};

sheep::sheep(const std::string& file_path, SDL_Surface* window_surface_ptr) : animal(file_path, window_surface_ptr, true, true){}

void sheep::move(){
    int surface_width = image_ptr_->clip_rect.w;
    int surface_height = image_ptr_->clip_rect.h;

    if (posY_ >= frame_height - frame_boundary - surface_height)
      vertical_direction_ = false;

    if (posY_ <= frame_boundary)
      vertical_direction_ = true;

    if (posX_ >= frame_width - frame_boundary - surface_width)
      horizontal_direction_ = false;

    if (posX_ <= frame_boundary)
      horizontal_direction_ = true;

    if (vertical_direction_)
      posY_+=1;

    if (!vertical_direction_)
      posY_-=1;

    if (horizontal_direction_)
      posX_+=1;

    if (!horizontal_direction_)
      posX_-=1;
};

sheep::~sheep(){
    SDL_FreeSurface(image_ptr_);
    std::cout << "Le mouton a disparu !" << std::endl;
};


wolf::wolf(const std::string& file_path, SDL_Surface* window_surface_ptr) : animal(file_path, window_surface_ptr, false, false){}

wolf::~wolf() {
  std::cout << "Le loup n'est plus la !" << std::endl;
  SDL_FreeSurface(image_ptr_);
}

void wolf::move()
{
    int surface_width = image_ptr_->clip_rect.w;
    int surface_height = image_ptr_->clip_rect.h;

    if (posY_ >= frame_height - frame_boundary - surface_height)
      vertical_direction_ = false;

    if (posY_ <= frame_boundary)
      vertical_direction_ = true;

    if (posX_ >= frame_width - frame_boundary - surface_width)
      horizontal_direction_ = false;

    if (posX_ <= frame_boundary)
      horizontal_direction_ = true;

    if (vertical_direction_)
      posY_+=1;

    else
      posY_-=1;

    if (horizontal_direction_)
      posX_+=1;
    else
      posX_-=1;
};

ground::ground() : animals_{std::vector<std::shared_ptr<animal>>()}{}

void ground::add_animal(const std::shared_ptr<animal>& a) {
    animals_.push_back(a);
}

std::vector<std::shared_ptr<animal>> ground::getAnimals() const {
    return animals_;
}

void ground::update() const {
    for (const auto& a : animals_) {
      a->move();
      a->draw();
    }
}

application::application(unsigned int n_sheep, unsigned int n_wolf) {

    // srand((unsigned)time(nullptr));

    window_ptr_ = SDL_CreateWindow("Sheep vs Wolf", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0 /* Nada */);

    window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);

    ground_ = ground();

    SDL_Event e;
    window_event_ = e;

    std::string sheep_path = "../../media/sheep.png";
    std::string wolf_path = "../../media/wolf.png";


    //let's make things colorful.
    SDL_FillRect(window_surface_ptr_ ,nullptr, SDL_MapRGB(window_surface_ptr_->format,0,127,0));

    for (int i = 0; i < n_sheep; i++) {
      auto s = std::make_shared<sheep>(sheep_path, window_surface_ptr_);
      ground_.add_animal(s);
      s->draw();
    }

    for (int i = 0; i < n_wolf; i++){
      auto s = std::make_shared<wolf>(wolf_path, window_surface_ptr_);
      ground_.add_animal(s);
      s->draw();
    }
    SDL_UpdateWindowSurface(window_ptr_);

}

application::~application() {
    SDL_FreeSurface(window_surface_ptr_);
    SDL_DestroyWindow(window_ptr_);
    std::cout << "Jeu fini." << std::endl;
}


int application::loop(unsigned period) {

    srand((unsigned)time(nullptr));

    Uint32 currentTime = 0;
    int lastTime = 0;
    auto zoo = ground_.getAnimals();

    while (currentTime <= period) {

      //This terminates the application, if we... try to close it
      while (SDL_PollEvent(&window_event_))
        if (window_event_.type == SDL_QUIT)
          return 0;

      SDL_FillRect(window_surface_ptr_ ,nullptr, SDL_MapRGB(window_surface_ptr_->format,0,127,0));
      ground_.update();
      currentTime = SDL_GetTicks();
      SDL_UpdateWindowSurface(window_ptr_);
      SDL_Delay((Uint32)frame_time);

    }
    return 1;
}