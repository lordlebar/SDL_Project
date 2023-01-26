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

void init()
{
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

SDL_Surface *load_surface_for(const std::string &path, SDL_Surface *window_surface_ptr)
{

  if (!window_surface_ptr)
  {
    std::cout << "No valid window surface passed as argument. Bad." << std::endl;
    return (nullptr);
  }

  int length = (int)path.length();
  char new_file_path[length];
  strcpy(new_file_path, path.c_str());

  SDL_Surface *surf = SDL_ConvertSurface(IMG_Load(new_file_path), window_surface_ptr->format, 0);
  if (!surf)
  {
    std::cout << "Error during creation of surface." << std::endl;
    return (nullptr);
  }

  return (surf);
}



// Constructor for the sheep class, derived from animal
sheep::sheep(const std::string &file_path, SDL_Surface *window_surface_ptr) : animal(file_path, window_surface_ptr, true, true) {}

// method to move the sheep (override the animal move method)
void sheep::move()
{
  // Get the window size
  int surface_width = image_ptr_->clip_rect.w;
  int surface_height = image_ptr_->clip_rect.h;
  auto target = wolfs_[0];
  float min = MAXFLOAT;
  bool alertwolf = false;

  // Find the closest wolf
  for (int i = 0; i < wolfs_.size(); i++)
  {
    // Check if the wolf is closer than the previous one
    if (sqrt(pow((posX_ - wolfs_[i]->posX_), 2) + pow((posY_ - wolfs_[i]->posY_), 2)) < min)
    {
      min = sqrt(pow((posX_ - wolfs_[i]->posX_), 2) + pow((posY_ - wolfs_[i]->posY_), 2));
      target = wolfs_[i];
    }
  }

  // Run the sheep away from the wolf if it is too close
  if (min < 120)
  {
    alertwolf = true;
  }

  // Move the sheep according to the wolf position
  if (alertwolf)
  {
    if (posY_ > target->posY_ && posY_ < frame_height - frame_boundary - surface_height)
      posY_ += 0.6;

    if (posY_ < target->posY_ && posY_ > frame_boundary)
      posY_ -= 0.6;

    if (posX_ > target->posX_ && posX_ < frame_width - frame_boundary - surface_width)
      posX_ += 0.6;

    if (posX_ < target->posX_ && posX_ > frame_boundary)
      posX_ -= 0.6;
  }

  // Move the sheep randomly
  else
  {
    if (posY_ >= frame_height - frame_boundary - surface_height)
      vertical_direction_ = false;

    if (posY_ <= frame_boundary)
      vertical_direction_ = true;

    if (posX_ >= frame_width - frame_boundary - surface_width)
      horizontal_direction_ = false;

    if (posX_ <= frame_boundary)
      horizontal_direction_ = true;

    if (vertical_direction_)
      posY_ += 0.6;

    if (!vertical_direction_)
      posY_ -= 0.6;

    if (horizontal_direction_)
      posX_ += 0.6;

    if (!horizontal_direction_)
      posX_ -= 0.6;
  }
  if (!target->is_alive)
  {
    // Remove the dead wolf from the list of wolfs
    wolfs_.erase(std::remove(wolfs_.begin(), wolfs_.end(), target), wolfs_.end());
    std::cout << "Un loup est mort" << std::endl;
  }
  if (wolfs_.size() <= 0)
  {
    std::cout << "You won ! Tous les loup sont morts" << std::endl;
    exit(0);
  }
};

// Destructor for the sheep class
sheep::~sheep()
{
  SDL_FreeSurface(image_ptr_);
  std::cout << "Le mouton a disparu" << std::endl;
};

// add a wolf to the list of wolfs
void sheep::addListOfWolfs(std::shared_ptr<animal> &wolf)
{
  wolfs_.push_back(wolf);
}

// Constructor for the wolf class, derived from animal
wolf::wolf(const std::string &file_path, SDL_Surface *window_surface_ptr) : animal(file_path, window_surface_ptr, false, false) {}

// destructor for the wolf class
wolf::~wolf()
{
  std::cout << "Le loup n'est plus la !" << std::endl;
  SDL_FreeSurface(image_ptr_);
}

// method to move the wolf (override the animal move method)
void wolf::move()
{
  // Get the window size
  int surface_width = image_ptr_->clip_rect.w;
  int surface_height = image_ptr_->clip_rect.h;
  auto closestSheep = std::shared_ptr(sheeps_[0]);
  auto closestShepherdDog = std::shared_ptr(shepherd_dog_);
  float min = MAXFLOAT;
  bool alertdog = false;

  // Find the closest sheep
  for (int i = 0; i < sheeps_.size(); i++)
  {
    // Check if the sheep is closer than the previous one
    if (sqrt(pow((posX_ - sheeps_[i]->posX_), 2) + pow((posY_ - sheeps_[i]->posY_), 2)) < min)
    {
      min = sqrt(pow((posX_ - sheeps_[i]->posX_), 2) + pow((posY_ - sheeps_[i]->posY_), 2));
      closestSheep = std::shared_ptr(sheeps_[i]);
    }
  }

  float distance_dog = sqrt(pow((posX_ - shepherd_dog_->posX_), 2) + pow((posY_ - shepherd_dog_->posY_), 2));

  // Run the wolf away from the shepherd dog if it is too close
  if (distance_dog < 150)
  {
    alertdog = true;
  }

  // Move the wolf according to the shepherd dog position
  if (alertdog)
  {
    if (posY_ >= closestShepherdDog->posY_)
      vertical_direction_ = false;

    if (posY_ <= closestShepherdDog->posY_)
      vertical_direction_ = true;

    if (posX_ >= closestShepherdDog->posX_)
      horizontal_direction_ = false;

    if (posX_ <= closestShepherdDog->posX_)
      horizontal_direction_ = true;

    if (vertical_direction_)
      posY_ -= 0.5;
    if (!vertical_direction_)
      posY_ += 0.5;
    if (horizontal_direction_)
      posX_ -= 0.5;
    if (!horizontal_direction_)
      posX_ += 0.5;
  }

  // Move the wolf according to the sheep position
  else
  {
    if (posY_ >= closestSheep->posY_)
      vertical_direction_ = false;

    if (posY_ <= closestSheep->posY_)
      vertical_direction_ = true;

    if (posX_ >= closestSheep->posX_)
      horizontal_direction_ = false;

    if (posX_ <= closestSheep->posX_)
      horizontal_direction_ = true;

    if (vertical_direction_)
      posY_ += 0.5;
    if (!vertical_direction_)
      posY_ -= 0.5;
    if (horizontal_direction_)
      posX_ += 0.5;
    if (!horizontal_direction_)
      posX_ -= 0.5;
  }

  // Check if the sheep is dead
  if (!closestSheep->is_alive)
  {
    sheeps_.erase(std::remove(sheeps_.begin(), sheeps_.end(), closestSheep), sheeps_.end());
  }

  // Game over if the wolf eats all the sheep
  if (sheeps_.size() == 0)
  {
    std::cout << "Game Over" << std::endl;
    exit(0);
  }

  // Eat the sheep if it is close enough
  if (min < 50)
  {
    hunger_ += 20;
    std::cout << "Mouton mangé" << std::endl;
    sheeps_.erase(std::remove(sheeps_.begin(), sheeps_.end(), closestSheep), sheeps_.end());
    closestSheep->is_alive = false;
  }

  // Decrease the hunger of the wolf through time
  hunger_ -= 0.01;

  // the wolf is dead if it is too hungry
  if (hunger_ <= 0)
  {
    this->is_alive = false;
  }
}

// add a sheep to the list of sheeps
void wolf::addListOfSheeps(std::shared_ptr<animal> &sheep)
{
  sheeps_.push_back(sheep);
}

// add a shepherd dog to the list of shepherd dogs
void wolf::addShepherdDog(std::shared_ptr<animal> &shepherd_dog)
{
  shepherd_dog_ = shepherd_dog;

}

// Constructor for the shepherd dog class, derived from animal
shepherd_dog::shepherd_dog(const std::string &file_path, SDL_Surface *window_surface_ptr) : animal(file_path, window_surface_ptr, false, false) {}

// Destructor for the shepherd dog class
shepherd_dog::~shepherd_dog()
{
  std::cout << "Le chien berger n'est plus la !" << std::endl;
  SDL_FreeSurface(image_ptr_);
}


// method to move the shepherd dog (override the animal move method)
void shepherd_dog::move()
{
  // shepherd position
  float player_x = shepherd_->posX_;
  float player_y = shepherd_->posY_;

  int radius = 100;
  angle_ += 0.009;

 // circular movement
  posX_ = player_x + radius * cos(angle_);
  posY_ = player_y + radius * sin(angle_);
}

// add a shepherd to the shepherd dog
void shepherd_dog::addShepherd(std::shared_ptr<playable_character> &shepherd)
{
  shepherd_ = shepherd;
}

// Constructor for the playable character class
playable_character::playable_character(const std::string &file_path, SDL_Surface *window_surface_ptr)
    : window_surface_ptr_{window_surface_ptr}
{

  image_ptr_ = load_surface_for(file_path, window_surface_ptr);
  if (image_ptr_ == nullptr)
    throw std::runtime_error("playable_character::playable_character(): " + std::string(SDL_GetError()));

  // Random spawn position
  posX_ = rand() % (frame_width - frame_boundary - image_ptr_->w) + frame_boundary;
  posY_ = rand() % (frame_height - frame_boundary - image_ptr_->h) + frame_boundary;
};

// draw the playable character
void playable_character::draw() const
{
  if (window_surface_ptr_ == nullptr)
    throw std::runtime_error("playable_character::draw(): window_surface_ptr_ is null");

  SDL_Rect position;
  position.x = posX_;
  position.y = posY_;

  SDL_BlitSurface(image_ptr_, nullptr, window_surface_ptr_, &position);
}

// constructor for the shepherd class, derived from playable character
shepherd::shepherd(const std::string &file_path, SDL_Surface *window_surface_ptr) : playable_character(file_path, window_surface_ptr) {}


// Destructor for the shepherd class
shepherd::~shepherd()
{
  std::cout << "Le berger a disparu" << std::endl;
  SDL_FreeSurface(image_ptr_);
}

// method to move the shepherd (override the playable character move method)
void shepherd::move(const Uint8 *keystate)
{
  if (keystate[SDL_SCANCODE_UP] && posY_ > frame_boundary)
    posY_ -= 0.5;
  if (keystate[SDL_SCANCODE_DOWN] && posY_ < frame_height - frame_boundary - image_ptr_->h)
    posY_ += 0.5;
  if (keystate[SDL_SCANCODE_LEFT] && posX_ > frame_boundary)
    posX_ -= 0.5;
  if (keystate[SDL_SCANCODE_RIGHT] && posX_ < frame_width - frame_boundary - image_ptr_->w)
    posX_ += 0.5;
}

// Constructor for the animal class
animal::animal(const std::string &file_path, SDL_Surface *window_surface_ptr, bool horizontal_direction, bool vertical_direction)
    : window_surface_ptr_{window_surface_ptr}, horizontal_direction_{horizontal_direction}, vertical_direction_{vertical_direction}
{

  image_ptr_ = load_surface_for(file_path, window_surface_ptr);
  if (image_ptr_ == nullptr)
    throw std::runtime_error("animal::animal(): " + std::string(SDL_GetError()));

  // Set random position of the animal
  posX_ = rand() % (frame_width - frame_boundary - image_ptr_->w) + frame_boundary;
  posY_ = rand() % (frame_height - frame_boundary - image_ptr_->h) + frame_boundary;
};

// draw the animal on the ground
void animal::draw() const
{
  if (window_surface_ptr_ == nullptr || image_ptr_ == nullptr)
  {
    std::cout << "pointers aren't ok, bro, do something";
    return;
  }

  Uint32 color_key = SDL_MapRGB(image_ptr_->format, 0, 0, 0);
  SDL_SetColorKey(image_ptr_, SDL_TRUE, color_key);

  // rectangle to draw the animal
  SDL_Rect sheep_rect;
  sheep_rect.x = posX_;
  sheep_rect.y = posY_;

  SDL_BlitSurface(image_ptr_, nullptr, window_surface_ptr_, &sheep_rect);
};

// constructor ground class
ground::ground() : animals_{std::vector<std::shared_ptr<animal>>()} {}

// add an animal to the list of animals
void ground::add_animal(const std::shared_ptr<animal> &a)
{
  animals_.push_back(a);
}

// add a playable character
void ground::add_shepherd(const std::shared_ptr<playable_character> &s)
{
  shepherd_ = s;
}

// get the list of animals
std::vector<std::shared_ptr<animal>> ground::getAnimals() const
{
  return animals_;
}

// get the shepherd
std::shared_ptr<playable_character> ground::getShepherd() const
{
  return shepherd_;
}

// update the ground
void ground::update() const
{
  for (const auto &a : animals_)
  {
    if (a->is_alive)
    {
      a->move();
      a->draw();
    }
  }
  shepherd_->move(SDL_GetKeyboardState(nullptr));
  shepherd_->draw();
}

// constructor for the application class
application::application(unsigned int n_sheep, unsigned int n_wolf)
{

  srand((unsigned)time(nullptr));

  window_ptr_ = SDL_CreateWindow("Sheep vs Wolf", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0 /* Nada */);

  window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);

  ground_ = ground();

  SDL_Event e;
  window_event_ = e;

  std::string sheep_path = "../../media/sheep.png";
  std::string wolf_path = "../../media/wolf.png";
  std::string shepherd_path = "../../media/shepherd.png";
  std::string shepherd_dog_path = "../../media/shepherd_dog.png";

  SDL_FillRect(window_surface_ptr_, nullptr, SDL_MapRGB(window_surface_ptr_->format, 0, 127, 0));

  std::vector<std::shared_ptr<animal>> tmpsheeps;
  std::vector<std::shared_ptr<animal>> tmpwolfs;
  std::shared_ptr<playable_character> tmpshepherd;
  std::shared_ptr<animal> tmpshepherd_dog;

  // Create the shepherd on the ground
  auto s = std::make_shared<shepherd>(shepherd_path, window_surface_ptr_);
  tmpshepherd = s;
  ground_.add_shepherd(s);
  s->draw();

  // Create the shepherd dog on the ground
  auto s_dog = std::make_shared<shepherd_dog>(shepherd_dog_path, window_surface_ptr_);
  tmpshepherd_dog = s_dog;
  ground_.add_animal(s_dog);
  s_dog->addShepherd(tmpshepherd);
  s_dog->draw();

  // Create the sheep on the ground
  for (int i = 0; i < n_sheep; i++)
  {
    auto s = std::make_shared<sheep>(sheep_path, window_surface_ptr_);
    tmpsheeps.push_back(s);
  }

  // Create the wolf on the ground
  for (int i = 0; i < n_wolf; i++)
  {
    auto s = std::make_shared<wolf>(wolf_path, window_surface_ptr_);
    ground_.add_animal(s);
    tmpwolfs.push_back(s);
    s->addShepherdDog(tmpshepherd_dog);
    for (int j = 0; j < n_sheep; j++)
    {
      s->addListOfSheeps(tmpsheeps[j]);
    }
    s->draw();
  }

  // Add the sheep to the ground
  for (int i = 0; i < n_sheep; i++)
  {
    ground_.add_animal(tmpsheeps[i]);
    for (int j = 0; j < n_wolf; j++)
    {
      // Add the wolf to the list of wolf of the sheep
      std::dynamic_pointer_cast<sheep>(tmpsheeps[i])->addListOfWolfs(tmpwolfs[j]);
    }
    tmpsheeps[i]->draw();
  }

  // Clear the temporary vectors
  tmpsheeps.clear();
  tmpwolfs.clear();
  tmpshepherd.reset();
  tmpshepherd_dog.reset();

  SDL_UpdateWindowSurface(window_ptr_);
}

// destructor for the application class
application::~application()
{
  SDL_FreeSurface(window_surface_ptr_);
  SDL_DestroyWindow(window_ptr_);
  std::cout << "Jeu fini." << std::endl;
}

// loop of the application
int application::loop(unsigned period)
{

  srand((unsigned)time(nullptr));

  Uint32 currentTime = 0;
  int lastTime = 0;
  auto map = ground_.getAnimals();

  while (currentTime <= period)
  {

    while (SDL_PollEvent(&window_event_))
      if (window_event_.type == SDL_QUIT)
        return 0;

    SDL_FillRect(window_surface_ptr_, nullptr, SDL_MapRGB(window_surface_ptr_->format, 0, 127, 0));
    ground_.update();
    currentTime = SDL_GetTicks();
    SDL_UpdateWindowSurface(window_ptr_);
    SDL_Delay((Uint32)frame_time);
  }
  return 1;
}