#pragma once

#include <typeindex>
#include <unordered_map>
#include <memory>
#include "IComponent.hpp"

struct Entity
{
    std::unordered_map<std::type_index, std::shared_ptr<IComponent>> components;

    Entity() = default;

    template<class TComponent>
    void AddComponent(const std::shared_ptr<IComponent>& component)
    {
        components[typeid(TComponent)] = component;
    }

    template<class TComponent>
    std::shared_ptr<TComponent> GetComponent()
    {
        return std::dynamic_pointer_cast<TComponent>(components[typeid(TComponent)]);
    }
};