################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CreationalPattern/BuilderPattern.cpp \
../src/CreationalPattern/FactoryPattern.cpp \
../src/CreationalPattern/PrototypePattern.cpp \
../src/CreationalPattern/SingletonPattern.cpp 

OBJS += \
./src/CreationalPattern/BuilderPattern.o \
./src/CreationalPattern/FactoryPattern.o \
./src/CreationalPattern/PrototypePattern.o \
./src/CreationalPattern/SingletonPattern.o 

CPP_DEPS += \
./src/CreationalPattern/BuilderPattern.d \
./src/CreationalPattern/FactoryPattern.d \
./src/CreationalPattern/PrototypePattern.d \
./src/CreationalPattern/SingletonPattern.d 


# Each subdirectory must supply rules for building sources it contributes
src/CreationalPattern/%.o: ../src/CreationalPattern/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


