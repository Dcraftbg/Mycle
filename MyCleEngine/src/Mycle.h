#pragma once



// TODO: Implement Shaders
// TODO: Implement Textures and Images (separate the two I hope)
// TODO: Implement all of the math, including QUANTERIONS (I hate those), to be able to make a dynamic camera and 3D raytracing! (I want to do that, it seems fun and the math isn't too bad :D for me at least hehe)
// TODO: Decide what logger to use:
//     - spdlog - which adds a lot of compile time, but is more flexible and provides a lot of features
//     - Colorita - my own logger, which is literally 334 lines of code and doesn't depend on the standard C++ library (because I hate that shit)
// TODO: Implement Mat4x4 math for this. All custom. I don't want glm (idealy)! 
// TODO: Decide if the exception system is necessary or not - because it may add some overhead, not exactly sure :|
// TODO: Implement Text rendering with FreeType - I haven't tried that so I'll have to experiment :D which is always fun
// TODO: Implement Input event handling - thats on the horizon
// TODO: Make a full engine editor maybe? Maybe expand this engine to be its own thing
// TODO: Implement what Mycle was all about, the youtube algorithm recomendation stuff :D
#include "Mycle/Utils.h"
#include "Mycle/Application.h"
#include "Mycle/ContextManager.h"
#include "Mycle/VertexArray.h"
#include "Mycle/VertexBuffer.h"
#include "Mycle/IndexBufffer.h"
#include "Mycle/Vector.h"
#include "Mycle/Random.h"
#include "Mycle/Renderer.h"
#include "Mycle/Memory.h"
#include "Mycle/Entry.h"