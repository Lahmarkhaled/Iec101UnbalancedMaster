

#pragma once

#include <IoUtility/Organizer/InternalSubOrganizer.h>
#include <vector>



namespace Iec101 {
	namespace Physical {
		class PhysicalLayer;
		class PhysicalLayerInternal;
	}

	class Iec101Organizer;

	class Iec101InternalOrganizer : public Io::Organizer::InternalSubOrganizer {
	public:
		Iec101InternalOrganizer(Io::Organizer::IoInternalOrganizer& ioInternalOrganizer, Iec101Organizer* iec101Organizer);

		void AddPhysicalLayer(std::unique_ptr<Iec101::Physical::PhysicalLayer>&& physicalLayer);
	private:
		Iec101Organizer* m_iec101Organizer;

		std::vector<std::unique_ptr<Iec101::Physical::PhysicalLayerInternal>> m_physicalLayerInternals;

	public:
		void FlushLogs() override;
	};
}