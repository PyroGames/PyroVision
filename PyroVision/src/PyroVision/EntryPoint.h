#pragma once

#ifdef PV_PLATFORM_WINDOWS

extern PV::Application* PV::CreateApplication();

int main(int argc, char** argv) {

	auto app = PV::CreateApplication();

	app->Run();

	delete app;
	return 0;
}

#endif