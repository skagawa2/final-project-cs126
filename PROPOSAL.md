# [SELECTED] Final Project Proposal 1: Ray Marching using a Distance Estimator

My first (considering this gets denied) project proposal is to create a graphics engine using ray marching to visualize shapes. The "significant" library (it was difficult trying to find one because of the nature of the project) I will be using will be ofxGui in order to add customization to he running app.

## Inspiration

The main inspiration/motivation/basis for this project include two YouTube videos:
* [Coding Adventure: Ray Marching - Sebastian Lague](https://www.youtube.com/watch?v=Cp5WWtMoeKg)
* [How to Make 3D Fractals - CodeParade](https://www.youtube.com/watch?v=svLzmFuSBhk)

These two videos show the process of [Ray Marching](https://en.wikipedia.org/wiki/Volume_ray_casting), or the idea of "marching" a light ray (in the context of creating a camera) along a 3D space until it hits an object, when we can display the pixel color on the screen. Since the idea of re-creating a camera is more vanilla, finding an external library that could outsource my work was difficult, since there isn't really that much advanced math required, or is a 3D graphics library required because I would be creating it.

## Goals
* Understanding Ray Marching as well as Distance Estimators and ray-based graphics engines in general
* Implementing a Ray Marching "camera" using a Distance Estimator as a method of decreasing computation
* (Using multi-threading to decrease computation time)
* Experimenting with different features of Ray Marching that make it better than Ray Tracing
* Implementing a fractal from the video by Code Parade
* Finding a way to control he camera and move it around an environment
* (Finding other 3D fractals to draw on screen)

## Process

### Week 1 (Week of April 9)
* Learn abut Ray Marching and implement a distance function to find distances between multiple oF objects
* Figure out a way to implement a "ray" (either ofxRaycaster or my own implementation)
* (Figure out a way to create custom shapes/equations)

### Week 2 (Week of April 16)
* Implement ray marching (multithreading to decrease computation time?) to display a simple shape
* Implement a fractal using CodeParade video

### Week 3 (Week of April 23)
* Figure out ways to "move" around in the environment
* Add shading using Sebastian Lague video

### Presentation (Week of April 30)


# Final Project Proposal 2: Environment Generator

My second project proposal is to create a terrain generation engine using 3D graphics libraries and (hopefully) realistic-looking graphics. The significant library would probably just be ofx3D in order to view the scene that I would have created.

## Inspiration

The main inspiration is similar to the last:
* [Compute Shaders - Sebastian Lague](https://www.youtube.com/watch?v=9RHGLZLUuwc)
* [Hydraulic Erosion - Sebastian Lague](https://www.youtube.com/watch?v=eaXk97ujbPQ)
* [Planet Generation - Sebastian Lague](https://www.youtube.com/watch?v=QN39W020LqU)

(Clearly, his videos were very inspiring, even though they were in Unity and C#)
These three videos show the process of creating realistic looking environments and the various optimizations that must be made in order to execute the large amount of computations in a reasonable amount of time. My current plan is to at least attempt to mimic the result from the Hydraulic Erosion video, in which Sebastian Lague was able to use parallel GPU processes in order to compute the directions that randomly placed water droplets would go on a mountainous terrain, then proceed to start coloring the terrain using the "flatness" of the terrain. The other aspect was the actual terrain generation. With a similar process to his (and with ofx3D), I believe that it wouldn't be impossible to create a wireframe of various heights that could mimic a mountain and display it using an easyCam or something similar.

## Goals
* Learn about various terrain forming and the aspects that can be mimicked with computer graphics (so probably not trees or individual blades of grass)
* Implement a smoothing function and a terrain noise generator to create realistic terrain
* Learn about multithreading and/or performance optimizations for dropping water droplets
* Have fun with the various settings of the terrain generation to create realistic environments

## Process

### Week 1 (Week of April 9)
* Create and display a smooth noise generated terrain using ofx3D
* Look up any other terrain generation entities that could look fun to implement (seeds -> trees? water?)

### Week 2 (Week of April 16)
* Implement the water droplets to create the effect of erosion

### Week 3 (Week of April 23)
* If needed, experiment with efficiency upgrades to the water droplet erosion simulation
* Experiment with any other features that can be added (color based on "flatness," water, etc.)

### Presentation (Week of April 30)
