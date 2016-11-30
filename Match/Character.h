//
//Character.h
//

#ifndef CHARACTER_H
#define CHARACTER_H

//#include "Match.h"
#include "Movable.h"
#include "Non_movables.h"


class Character : public Movable
{
  private:

    struct Speed_vector
    {
	    int x_speed{};
	    int y_speed{};
    };

    Speed_vector speed_vector{};

    int health{};

    Health_bar health_bar;

    // unique_ptr<Attack> curr_attack{new Attack()}; //Kanske måsvingar vid Attack

  public:

    ~Character() = default;

    Character() = default;

    Character(int,int,int,int,int,int,int,int);

    void set_x_speed(int);

    void set_y_speed(int);

    int get_x_speed() const;

    int get_y_speed() const;

    int get_speed() const;

    void move() override;
    
    //void jump();

    int get_texture_index();// override;

    //void attack(int, Match & match);

    void lose_health(int);

};

#endif
