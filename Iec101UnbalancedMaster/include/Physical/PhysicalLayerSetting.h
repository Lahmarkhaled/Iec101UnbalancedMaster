#pragma once

#include <cstdint>

namespace Iec101 {
	namespace Physical {
		constexpr uint8_t kDefaultLinkAddressSize = 1;

		class PhysicalLayerSetting {
		public:
			PhysicalLayerSetting(uint8_t addressSize = kDefaultLinkAddressSize);

			uint8_t GetAddressSize() const;

		private:
			uint8_t m_addressSize;
		};
	}
}