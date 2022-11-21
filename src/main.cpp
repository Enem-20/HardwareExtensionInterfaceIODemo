#include "HardwareExtensionModule.h"

#include "LibraryProcessor.h"
#include "ConfigLoader.h"

#include <vector>
#include <iostream>

int main(int argc, char** argv) {
	ConfigLoader::Init(argv[0]);
	LibraryProcessor::LoadLibraries();

	HardwareExtensionModule extensionModule("Head", ConfigLoader::GetConfigFromFile("configs/IOConfigDefault.json"));


	while (!extensionModule.isTaskFinished()) {
		auto analogPins = extensionModule.GetValuesFromAnalogPins();
		std::cout << "Analog pins:" << '\n';
		for (auto pin : analogPins) {
			std::cout << pin.first << ":" << pin.second << '\n';
		}

		auto digitalInputPins = extensionModule.GetInputPinStates();

		std::cout << "Input pins:" << '\n';
		for (auto pin : digitalInputPins) {
			std::cout << pin.first << ":" << pin.second << '\n';
		}

		auto digitalOutputPins = extensionModule.GetOutputPinStates();

		std::cout << "Output pins:" << '\n';
		for (auto pin : digitalOutputPins) {
			std::cout << pin.first << ":" << pin.second << '\n';
		}

		Sleep(500);
	}

	return 0;
}