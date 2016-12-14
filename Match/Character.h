//
//Character.h
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "../Object.h"
#include "Non_movables.h"
#include "Attack.h"


class Character : public Object
{
  private:

    struct Speed_vector
    {
	    int x_speed{};
	    int y_speed{};

    };

    Speed_vector speed_vector{};

    int health{};

    bool in_air{};

    bool is_stumped{};

    Attack curr_attack{};

    bool has_attack;

    std::vector<Projectile> projectiles{};

    Health_bar health_bar;

    Position old_position{};

    int direction{};


  public:

    ~Character() = default;

    Character() = default;

    Character(int,int,int,int,std::initializer_list<std::string>,int,int);

    void set_x_pos(int);

    void set_y_pos(int);

    void set_in_air(bool);

    void set_is_stumped(bool);

    void set_x_speed(int);

    void set_y_speed(int);

    bool get_in_air() const;

    bool get_is_stumped() const;

    int get_x_speed() const;

    int get_y_speed() const;

    Object::Position & get_old_position();

    void move();

    void render(sf::RenderWindow &) override;

    void attack(int); //(int,int)

    void lose_health(int);

    int get_health();

    std::vector<Projectile> & get_projectiles();

};

#endif
