#include <Mycle.h>
#include <stdio.h>
#include <stdlib.h>
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_TRIANGLES 0x0004

size_t MAX_ALLOCATED_MEMORY = (640000*2);
size_t MAX_TEMPORARY_MEMORY_ALLOCATED = MAX_ALLOCATED_MEMORY / 2;
const char* TitleFormat = "DVD Simulator, corner hits: %zu, global memusage: %zu/%zu, temporary memusage: %zu/%zu";
class GameLayer : public Mycle::Application {
public:
	GameLayer() : window(nullptr)   {}
	~GameLayer() {}
	//static void onException(Mycle::Exception& exception) {
	//	fprintf(stderr, "ERROR: %s exception", exception.description);
	//	exit(1);
	//}
	//Mycle::ExceptionManager::ExceptionHandler getExceptionHandler() {
	//	return onException;
	//}
	Mycle::Memory::Config getMemconfig() {
		return { MAX_ALLOCATED_MEMORY, MAX_TEMPORARY_MEMORY_ALLOCATED };
	}
	void onWindowInit(Mycle::Window* win) {
		window = win;
		using Mycle::Vector2i;
		Vector2i resolution = window->WindowSize();
		width = 0.15f * (float)resolution.width;
		height = 0.15f * (float)resolution.height;
		UpdateTitle();
	}
	void onInit() override {
		seed = Mycle::Random::wang_hash(time(0));
		rect.Init();
		layout.Push<float>(2, false);
		Mycle::ContextManager::swapInterval(1);
	}
	void onUpdate(float deltaTime) override {
		//char buf[500] = { 0 };
		//seed = Mycle::Random::wang_hash(seed);
		//sprintf_s(buf, 500, "DVD Simulator, corner hits: %zu, Random Number: %u, Delta Time: %f", hits, seed,deltaTime);
		//window->SetTitle(buf);
		using Mycle::Vector2i;
		Vector2i resolution = window->WindowSize();
		//printf("resolution:\n x: %d\n y: %d\nPosition:\n x: %f\n y: %f\n",resolution.width,resolution.height,x,y);
		//if (((x + width + eps_x * deltaTime == (float)resolution.width || x + eps_x * deltaTime == 0) && (y + height + eps_y * deltaTime == (float)resolution.height || y + eps_y * deltaTime == 0))) {
		//	hits++;
		//}
		if (x +width+ eps_x * deltaTime    > (float)resolution.width  || x + eps_x * deltaTime < 0) {
			eps_x = -eps_x;
		}
		if (y + height + eps_y * deltaTime > (float)resolution.height || y + eps_y * deltaTime < 0) {
			eps_y = -eps_y;
		}
		if (x + width + eps_x * deltaTime <= (float)resolution.width && x + eps_x * deltaTime >= 0) {
			x += eps_x * deltaTime;
		}
		if (y + height  + eps_y * deltaTime <= (float)resolution.height && y + eps_y * deltaTime >= 0) {
			y += eps_y * deltaTime;
		}
		window->clear(backGroundColor);
		using Mycle::Vector2f;
		Vector2f* positions = (Vector2f*) Mycle::Memory::Temporary()->alloc(4  * sizeof(Vector2f));
		//UpdateTitle();
		//if (positions == nullptr) {
		//	fprintf(stderr, "Could not allocate :(");
		//	exit(1);
		//}
		//
		float fx      = (x      / (float)resolution.width )*2.0f-1.0f;
		float fy      = (y      / (float)resolution.height)*2.0f-1.0f;
		float fwidth  = (width  / (float)resolution.width );
		float fheight = (height / (float)resolution.height);
		float fx_width = ((x + width) / (float)resolution.width) * 2.0f - 1.0f;
		float fy_height = ((y + height) / (float)resolution.height) * 2.0f - 1.0f;
		positions[0] = { fx	         , fy };
		positions[1] = { fx_width , fy };
		positions[2] = { fx_width , fy_height };
		positions[3] = { fx          , fy_height };
		
		//vb.SendData(positions, 4*2*sizeof(float), GL_DYNAMIC_DRAW);
		//va.AddBuffer(vb, layout);
		//va.Bind();
		//ib.Bind();
		//
		//Mycle::ContextManager::drawElements(GL_TRIANGLES,ib.GetCount(),GL_UNSIGNED_INT,nullptr);
		
		//renderer.DrawTriangle({ x, y }, {x+width, y}, {x+width, y+height});
		//printf("final position:\n x: %f\n y: %f\n width: %f\n height: %f\n",fx,fy,fwidth,fheight);
		// renderer.DrawRect({ fx,fy }, { fx_width, fy }, { fx_width, fy_height }, { fx,fy_height });
		rect.Draw(layout, positions, 4 * sizeof(Mycle::Vector2f));
		UpdateTitle();
		/*
		


		triangle.points[0] = {x, y};
		triangle.points[1] = {x+width,y};
		triangle.points[2] = {x+width,y+height};
	
		Mycle::Renderer::DrawTriangle({x,y},{x+width, y}, {x+width, y+width});
		Mycle::Renderer::DrawQuads(...);
		Mycle::Renderer::DrawTriangle(triangle);
		*/
		
		//TemporaryAllocator.reset();
	}
	Mycle::WindowProps* getProps() override {
		return new Mycle::WindowProps(960, 540, "DVD Simulator, corner hits: 0");
	}
	void UpdateTitle() {
		char buf[500] = { 0 };
		sprintf_s(buf, 500, TitleFormat, hits, Mycle::Memory::Global()->memusage() - MAX_TEMPORARY_MEMORY_ALLOCATED, Mycle::Memory::Global()->capacity * sizeof(uintptr_t) - MAX_TEMPORARY_MEMORY_ALLOCATED, Mycle::Memory::Temporary()->memusage(), Mycle::Memory::Temporary()->capacity * sizeof(uintptr_t));
		window->SetTitle(buf);
	}
private:
	Mycle::Window* window;
	Mycle::VBLayout layout;
	//Mycle::IndexBuffer ib;
	//Mycle::VertexArray va;
	//Mycle::VertexBuffer vb;
	Mycle::Rectangle rect;
	Mycle::Renderer renderer;
	/*
	Mycle::Triangle triangle;
	*/


	uint32_t seed=0;
	Mycle::Vector4f backGroundColor{ 0.27734375f, 0.27734375f, 0.27734375f, 1.0f };
	float x=0.0f;
	float y=0.0f;
	float width  = 200.5f;
	float height = 80.5f;
	float eps_x  = 1000.0f/4;//0.25f*2;
	float eps_y  = 1000.0f/8;//0.125f*2;
	size_t hits=0;

};

Mycle::Application* Mycle::CreateApplication() {
	return new GameLayer();
}