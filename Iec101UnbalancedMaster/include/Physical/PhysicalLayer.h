#pragma once

#include <memory>

namespace Io {
	namespace Utility {
		namespace Connection {
			class ConnectionSettings;
		}
	}
}

namespace Iec101 {
	namespace Physical {
		class PhysicalLayerInternal;
		class PhysicalLayerSetting;

		class PhysicalLayer {
		public:
			PhysicalLayer();

			void Start(std::unique_ptr<Io::Utility::Connection::ConnectionSettings>&& connectionSettings, 
				std::unique_ptr<PhysicalLayerSetting>&& layerSetting);

			void SetInternalLayer(PhysicalLayerInternal* physicalInternalLayer);

		private:
			PhysicalLayerInternal* m_physicalLayerInternal;
		};
	}
}