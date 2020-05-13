################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/StruturalPattern/AdapterPattern.cpp \
../src/StruturalPattern/BridgePattern.cpp \
../src/StruturalPattern/CompositePattern.cpp \
../src/StruturalPattern/DecoratorPattern.cpp \
../src/StruturalPattern/FacadePattern.cpp \
../src/StruturalPattern/FlyweightPattern.cpp 

OBJS += \
./src/StruturalPattern/AdapterPattern.o \
./src/StruturalPattern/BridgePattern.o \
./src/StruturalPattern/CompositePattern.o \
./src/StruturalPattern/DecoratorPattern.o \
./src/StruturalPattern/FacadePattern.o \
./src/StruturalPattern/FlyweightPattern.o 

CPP_DEPS += \
./src/StruturalPattern/AdapterPattern.d \
./src/StruturalPattern/BridgePattern.d \
./src/StruturalPattern/CompositePattern.d \
./src/StruturalPattern/DecoratorPattern.d \
./src/StruturalPattern/FacadePattern.d \
./src/StruturalPattern/FlyweightPattern.d 


# Each subdirectory must supply rules for building sources it contributes
src/StruturalPattern/%.o: ../src/StruturalPattern/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


