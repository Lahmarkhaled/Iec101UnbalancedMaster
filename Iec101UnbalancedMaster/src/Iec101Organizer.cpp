#include <mutex>

#include <Iec101Organizer.h>

#include <Iec101InternalOrganizer.h>

using namespace Iec101;
using namespace Io::Organizer;

Iec101::Iec101Organizer::Iec101Organizer()
{
	m_iec101InternalOrganizer = nullptr;
}

void Iec101::Iec101Organizer::AddPhysicalLayer(std::unique_ptr<Iec101::Physical::PhysicalLayer>&& physicalLayer)
{
	std::lock_guard<std::mutex> lock(m_iec101InternalOrganizer->GetMutex());
	m_iec101InternalOrganizer->AddPhysicalLayer(std::move(physicalLayer));
}

void Iec101::Iec101Organizer::CreateInternalSubOrganizer(Io::Organizer::IoInternalOrganizer & ioInternalOrganizer)
{
	m_iec101InternalOrganizer = new Iec101InternalOrganizer(ioInternalOrganizer, this);
	m_internalSubOrganizer = m_iec101InternalOrganizer;
}
