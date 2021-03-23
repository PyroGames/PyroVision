#include <PyroVision.h>

class Sandbox : public PV::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}

private:
};

PV::Application* PV::CreateApplication() {
	return new Sandbox();
}