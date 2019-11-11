
#include <Iec101InternalOrganizer.h>

#include <Iec101Organizer.h>

#include <Physical/PhysicalLayer.h>
#include <Physical/PhysicalLayerInternal.h>

using namespace Io::Organizer;
using namespace Iec101::Physical;

Iec101::Iec101InternalOrganizer::Iec101InternalOrganizer(Io::Organizer::IoInternalOrganizer & ioInternalOrganizer, 
	Iec101Organizer * iec101Organizer)
	: InternalSubOrganizer(ioInternalOrganizer, *iec101Organizer), m_iec101Organizer(iec101Organizer)
{
}

void Iec101::Iec101InternalOrganizer::AddPhysicalLayer(std::unique_ptr<Iec101::Physical::PhysicalLayer>&& physicalLayer)
{
	auto pLayer = physicalLayer.get();

	auto internalLayer = std::make_unique<PhysicalLayerInternal>(*m_iec101Organizer, *this, std::move(physicalLayer));

	pLayer->SetInternalLayer(internalLayer.get());

	m_physicalLayerInternals.emplace_back(std::move(internalLayer));
}

void Iec101::Iec101InternalOrganizer::FlushLogs()
{
}
