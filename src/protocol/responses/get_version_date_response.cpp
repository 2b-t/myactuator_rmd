#include "myactuator_rmd/protocol/responses/get_version_date_response.hpp"

#include <cstdint>


namespace myactuator_rmd {
  
  std::uint32_t GetVersionDateResponse::getVersion() const noexcept {
    return getAs<std::uint32_t>(4);
  }

}
