#ifndef TBA_ACTION_HPP
#define TBA_ACTION_HPP

namespace tba {

typedef unsigned int character_id;
typedef unsigned int team_id;

enum class ActionType {
    ATTACK1,
    ATTACK2,
    ATTACK3
};

enum class DecisionMakerID { TestAutoInput, HumanControllable, DecisionTree };

class Action {
    private:
        character_id user_id;
        character_id target_id;
        int speed;
        ActionType type;

    public:

        Action(character_id user, character_id target, ActionType _type);
        ~Action();

        virtual bool operator<(const Action& other) const {
            return get_speed() < other.get_speed();
        }

        character_id get_user_id() const;
        character_id get_target_id() const;
        ActionType get_type() const;
        int get_speed() const;

    private:
};

}

#endif
