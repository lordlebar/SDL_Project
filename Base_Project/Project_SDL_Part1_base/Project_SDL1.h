﻿// SDL_Test.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

// Defintions
constexpr double frame_rate = 60.0; // refresh rate
constexpr double frame_time = 1. / frame_rate;
constexpr unsigned frame_width = 1400; // Width of window in pixel
constexpr unsigned frame_height = 900; // Height of window in pixel
// Minimal distance of animals to the border
// of the screen
constexpr unsigned frame_boundary = 100;

// Helper function to initialize SDL
void init();
SDL_Surface* load_surface_for(const std::string& path, SDL_Surface* window_surface_ptr);

class animal {
public:
  SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the
                                    // animal to be drawn, also non-owning
  SDL_Surface* image_ptr_; // The texture of the sheep (the loaded image), use
                           // load_surface_for
  // todo: Attribute(s) to define its position
  float posX_;
  float posY_;
  bool horizontal_direction_;
  bool vertical_direction_;
  bool is_alive = true;

public:
  animal(const std::string& file_path, SDL_Surface* window_surface_ptr, bool horizontal_direction, bool vertical_direction);
  // todo: The constructor has to load the sdl_surface that corresponds to the
  // texture
  virtual ~animal() = default; // todo: Use the destructor to release memory and "clean up
               // behind you"

  void draw() const; // todo: Draw the animal on the screen <-> window_surface_ptr.
                 // Note that this function is not virtual, it does not depend
                 // on the static type of the instance

  virtual void move() = 0; // todo: Animals move around, but in a different
                             // fashion depending on which type of animal
};


// Insert here:
// class sheep, derived from animal
class sheep : public animal {
public:
  std::vector<std::shared_ptr<animal>> wolfs_ = {};
  sheep(const std::string& file_path, SDL_Surface* window_surface_ptr);
  ~sheep() override;
  void move() override;
  void addListOfWolfs(std::shared_ptr<animal> &sheep);
};

// Insert here:
// class wolf, derived from animal
// Use only sheep at first. Once the application works
// for sheep you can add the wolves
class wolf : public animal {
public:
  std::vector<std::shared_ptr<animal>> sheeps_ = {}; 
  wolf(const std::string& file_path, SDL_Surface* window_surface_ptr); 
  ~wolf() override;
  void move() override;
  void addListOfSheeps(std::shared_ptr<animal> &sheep);
};

// The "ground" on which all the animals live (like the std::vector
// in the zoo example).
class ground {
private:
  // Attention, NON-OWNING ptr, again to the screen
  SDL_Surface* window_surface_ptr_;

  // Some attribute to store all the wolves and sheep
  // here
  std::vector<std::shared_ptr<animal>> animals_;
  unsigned frame = 0;

public:
  // todo: Ctor
  ground();
  // todo: Dtor, again for clean up (if necessary)
  ~ground() = default;
  // todo: Add an animal
  void add_animal(const std::shared_ptr<animal>& a);
   // todo: "refresh the screen": Move animals and draw them
  void update() const;
  // Possibly other methods, depends on your implementation
  [[nodiscard]] std::vector<std::shared_ptr<animal>> getAnimals() const;
};



// The application class, which is in charge of generating the window
class application {
private:
  // The following are OWNING ptrs
  SDL_Window* window_ptr_;
  SDL_Surface* window_surface_ptr_;
  SDL_Event window_event_;
  ground ground_;

  // Other attributes here, for example an instance of ground

public:
  // Ctor
  application(unsigned n_sheep, unsigned n_wolf);

  // dtor
  ~application();

  int loop(unsigned period); // main loop of the application.
                             // this ensures that the screen is updated
                             // at the correct rate.
                             // See SDL_GetTicks() and SDL_Delay() to enforce a
                             // duration the application should terminate after
                             // 'period' seconds
};

bool check_collision(SDL_Rect &first, SDL_Rect &second);