#include "myactuator_rmd_driver/messages/responses/version_date_response.hpp"

#include <cstdint>


namespace myactuator_rmd_driver {
  
  std::uint32_t VersionDateResponse::getVersion() const noexcept {
    return getAs<std::uint32_t>(4);
  }

}
