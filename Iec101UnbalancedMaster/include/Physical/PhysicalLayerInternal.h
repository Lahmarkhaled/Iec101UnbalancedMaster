
#pragma once

#include <IoUtility/Connection/ConnectionHelper.h>
#include <Physical/PhysicalLayerSetting.h> 

namespace Iec101 {
	class Iec101Organizer;
	class Iec101InternalOrganizer;

	namespace Physical {
		class PhysicalLayer;

		class PhysicalLayerInternal : public Io::Utility::Connection::ConnectionHelper {
		public:
			PhysicalLayerInternal(Iec101Organizer& iec101Organizer, Iec101InternalOrganizer& iec101InternalOrganizer,
				std::unique_ptr<PhysicalLayer>&& physicalLayer);

			void Start(std::unique_ptr<Io::Utility::Connection::ConnectionSettings>&& connectionSettings,
				std::unique_ptr<PhysicalLayerSetting>&& layerSetting);

		private:
			Iec101Organizer& m_iec101Organizer;
			Iec101InternalOrganizer& m_iec101InternalOrganizer;

			std::unique_ptr<PhysicalLayer> m_physicalLayer;
			std::unique_ptr<PhysicalLayerSetting> m_physicalLayerSetting;

		public: //ConnectionHelper
			void AddLog(std::string&& content) override;

		protected: //ConenctionHelper
			bool NeedFullIdentityLog() override;

			std::string GetObjectIsStartedLog() override;
			std::string GetObjectIsStoppedLog() override;
		};
	}
}