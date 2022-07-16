#include <iostream>
#include <string>

#include <intrin.h>

int main(int argc, char** argv)
{
	if (argc >= 2) {
		int function_id = std::stoul(std::string(argv[1]), nullptr, 16);
		int subfunction_id = 0;
		if (3 == argc) {
			subfunction_id = std::stoul(std::string(argv[2]), nullptr, 16);
		}
		int cpuInfo[4];
		__cpuidex(cpuInfo, function_id, subfunction_id);
		std::cout << "EAX: 0x" << std::hex << cpuInfo[0] << std::endl;
		std::cout << "EBX: 0x" << std::hex << cpuInfo[1] << std::endl;
		std::cout << "ECX: 0x" << std::hex << cpuInfo[2] << std::endl;
		std::cout << "EDX: 0x" << std::hex << cpuInfo[3] << std::endl;
	} else {
		std::cout << "cpuid.exe {function_id} {Optional - subfunction_id}" << std::endl;
		std::cout << "EXAMPLE - cpuid.exe 0x1337" << std::endl;
		std::cout << "EXAMPLE - cpuid.exe 0x1337 0x1337" << std::endl;
		return 1;
	}
	return 0;
}