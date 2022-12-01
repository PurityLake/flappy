#ifndef __FLAPPY_ENTITY_HPP__
#define __FLAPPY_ENTITY_HPP__

class Entity {
public:
    virtual ~Entity() = default;
    virtual void Update(float dt) = 0;
};

#endif /* __FLAPPY_ENTITY_HPP__ */