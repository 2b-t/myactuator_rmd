#include "myactuator_rmd_driver/messages/message.hpp"

#include <array>
#include <cstdint>


namespace myactuator_rmd_driver {
      
  std::array<std::uint8_t,8> const& Message::getData() const noexcept {
    return data_;
  }

}
