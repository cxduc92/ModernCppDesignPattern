################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BehavioralPattern/ChainOfResponsibility.cpp \
../src/BehavioralPattern/CommandPattern.cpp 

OBJS += \
./src/BehavioralPattern/ChainOfResponsibility.o \
./src/BehavioralPattern/CommandPattern.o 

CPP_DEPS += \
./src/BehavioralPattern/ChainOfResponsibility.d \
./src/BehavioralPattern/CommandPattern.d 


# Each subdirectory must supply rules for building sources it contributes
src/BehavioralPattern/%.o: ../src/BehavioralPattern/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


