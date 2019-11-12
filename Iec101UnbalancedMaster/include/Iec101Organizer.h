
#pragma once

#include <IoUtility/Organizer/SubOrganizer.h>

namespace Iec101 {
	namespace Physical {
		class PhysicalLayer;
	}

	class Iec101InternalOrganizer;
	class Iec101LogEntry;

	class Iec101Organizer : public Io::Organizer::SubOrganizer {
	public:
		Iec101Organizer();

		void AddPhysicalLayer(std::unique_ptr<Iec101::Physical::PhysicalLayer>&& physicalLayer);

	private:
		Iec101InternalOrganizer* m_iec101InternalOrganizer;
	public:
		void CreateInternalSubOrganizer(Io::Organizer::IoInternalOrganizer& ioInternalOrganizer) override;
	};
}