#include <cstdlib>

#include "include\CalcResourceFactory.h"
#include "include\CalcServiceSettingsFactory.h"
#include "include\CalcService.h"

int main(const int, const char**)
{
    auto calc_resource_factory = make_shared<CalcResourceFactory>();
    auto calc_service_settings_factory = 
        make_shared<CalcServiceSettingsFactory>();
    
    CalcService calc_service {
        calc_resource_factory, calc_service_settings_factory};
    
    calc_service.start();
    
    return EXIT_SUCCESS;
}