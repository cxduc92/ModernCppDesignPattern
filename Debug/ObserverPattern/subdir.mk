################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ObserverPattern/DummyProduct.cpp \
../ObserverPattern/Shop.cpp \
../ObserverPattern/Subject.cpp \
../ObserverPattern/main.cpp 

OBJS += \
./ObserverPattern/DummyProduct.o \
./ObserverPattern/Shop.o \
./ObserverPattern/Subject.o \
./ObserverPattern/main.o 

CPP_DEPS += \
./ObserverPattern/DummyProduct.d \
./ObserverPattern/Shop.d \
./ObserverPattern/Subject.d \
./ObserverPattern/main.d 


# Each subdirectory must supply rules for building sources it contributes
ObserverPattern/%.o: ../ObserverPattern/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


