/*
*  This file is part of openauto project.
*  Copyright (C) 2018 f1x.studio (Michal Szwaj)
*
*  openauto is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 3 of the License, or
*  (at your option) any later version.

*  openauto is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with openauto. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <thread>
#include <f1x/aasdk/USB/USBWrapper.hpp>
#include <f1x/aasdk/USB/AccessoryModeQueryChain.hpp>
#include <f1x/aasdk/USB/AccessoryModeQueryChainFactory.hpp>
#include <f1x/aasdk/USB/AccessoryModeQueryFactory.hpp>
#include <f1x/openauto/autoapp/USB/USBApp.hpp>
#include <f1x/openauto/autoapp/Configuration/IConfiguration.hpp>
#include <f1x/openauto/autoapp/Projection/AndroidAutoEntityFactory.hpp>
#include <f1x/openauto/autoapp/Projection/ServiceFactory.hpp>

namespace f1x
{
namespace openauto
{
namespace autoapp
{
namespace usb
{

class USBMain
{
public:
    USBMain(libusb_context* context);

    int exec(int argc, char* argv[]);

private:
    typedef std::vector<std::thread> ThreadPool;

    void startUSBWorkers();
    void startIOServiceWorkers();

    libusb_context* usbContext_;
    aasdk::usb::USBWrapper usbWrapper_;
    boost::asio::io_service ioService_;
    aasdk::usb::AccessoryModeQueryFactory queryFactory_;
    aasdk::usb::AccessoryModeQueryChainFactory queryChainFactory_;
    configuration::IConfiguration::Pointer configuration_;
    projection::ServiceFactory serviceFactory_;
    projection::AndroidAutoEntityFactory androidAutoEntityFactory_;
    autoapp::usb::USBApp::Pointer usbApp_;
    ThreadPool threadPool_;
};

}
}
}
}
