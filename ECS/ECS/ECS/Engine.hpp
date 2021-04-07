#pragma once

#include <typeindex>
#include <unordered_map>
#include <memory>
#include "ISystem.hpp"

struct Engine
{
    std::unordered_map<std::type_index, std::shared_ptr<ISystem>> systems;

    Engine() = default;

    template<class TSystem>
    void AddSystem(const std::shared_ptr<ISystem>& component)
    {
        systems[typeid(TSystem)] = component;
    }

    template<class TSystem>
    std::shared_ptr<TSystem> GetSystem()
    {
        return std::dynamic_pointer_cast<TSystem>(systems[typeid(TSystem)]);
    }

    void Update(float delta) const
    {
        for (const auto& [key, system] : systems)
        {
            system->Update(delta);
        }
    }
};
