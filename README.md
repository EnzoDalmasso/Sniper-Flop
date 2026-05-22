# Sniper-Flop

A 2D arcade physics simulation video game developed in **C++** using the **SFML** graphics library for rendering and the **Box2D** high-precision physics engine. The core gameplay revolves around solving interactive scenarios using a cannon that shoots an articulated character (*Ragdoll*), which reacts realistically to gravity, collisions, vector forces, and structural joints.

This project was developed individually and comprehensively during the early stages of my game development studies, serving as a solid foundation for understanding real-time physics engine integration, applied linear algebra, and the Object-Oriented Programming (OOP) paradigm.

## Key Features

- **Custom Ragdoll Physics:** Creation of a dynamic articulated body composed of 6 independent parts (head, torso, and limbs) interconnected via distance joints (`b2DistanceJoint`) configured with specific stiffness and damping values.
- **Dynamic Level System:** Scenario design featuring mechanics based on physics puzzles, including pendulums built with mechanical constraints, destructible barriers, and moving objectives.
- **Decoupled Game Loop:** Implementation of a synchronous game loop that processes user inputs, updates the Box2D physics world at a fixed timestep, and renders graphical components via SFML independently.
- **Vector Calculus & Trigonometry:** Real-time cannon orientation control using inverse trigonometric functions (`atan2f`) based on the cursor position, translating that direction into proportional force impulses to eject the character.

## Technologies & Tools

- **Language:** C++
- **Physics Engine:** Box2D (Rigid body simulation and joint constraints)
- **Multimedia & Graphics:** SFML (Simple and Fast Multimedia Library)
- **Development Environment:** Visual Studio IDE

## Project Architecture & Classes

The project stands out for its clear separation of concerns and modularization of the source code:

- **`main.cpp`:** The entry point of the application. It instantiates the main simulation object, defining the screen resolution (800x600) and window properties.
- **`administrador` (Core Structure):** The heart of the game's lifecycle. It initializes the SFML window, defines the physics world (`b2World`) with downward gravity, controls delta time (`sf::Clock`) to prevent fluctuations, and manages the state machine for scene switching (Menu, Level 1, Level 2).
- **`actor` (Graphical-Physics Wrapper Pattern):** Functions as a direct bridge between Box2D and SFML. It automates the synchronization of rigid body positions and the conversion of rotations from radians (physics) to degrees (graphics) for every rendered object.
- **`radgoll`:** Modulates the behavior of the articulated puppet. It encapsulates the definition of dynamic rigid bodies (`b2_dynamicBody`), their material properties (density, friction, and restitution/bounce), and the logic to apply simultaneous vector forces to its components when fired.
- **`menu`:** Manages the initial user interface, controlling the rendering of backgrounds and button sprites, and identifying clicks via spatial collisions within the graphical interface.
- **`nivel1` / `nivel2`:** Container classes for each scenario's game logic. Responsible for instantiating static geometry (floors, walls, ceilings), configuring mechanical objects (articulated pendulums and target boxes), and checking victory conditions.

## Mechanics & Technical Implementation

### 1. Graphical-Physics Decoupling (Actor Class)
To prevent excessive coupling between the graphics engine and the physics engine, the `actor` class extracts the `AABB` (Axis-Aligned Bounding Box) from the Box2D fixtures to automatically size and position the SFML shapes:
```cpp
for (b2Fixture* i = bdy_actor->GetFixtureList(); i; i = i->GetNext()) {
    dimensiones = i->GetAABB(0);
}
fig_actor->setSize({ dimensiones.GetExtents().x * 2, dimensiones.GetExtents().y * 2 });
fig_actor->setOrigin(fig_actor->getSize().x / 2.f, fig_actor->getSize().y / 2.f);
