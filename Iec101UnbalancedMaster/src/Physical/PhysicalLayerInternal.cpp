

#include <Physical/PhysicalLayerInternal.h>

#include <IoUtility/CommonResources.h>
#include <IoUtility/Connection/ConnectionHelper.h>
#include <Iec101Organizer.h>
#include <Iec101InternalOrganizer.h>

using namespace Iec101;
using namespace Iec101::Physical;

Iec101::Physical::PhysicalLayerInternal::PhysicalLayerInternal(Iec101Organizer & iec101Organizer, 
	Iec101InternalOrganizer & iec101InternalOrganizer, std::unique_ptr<PhysicalLayer>&& physicalLayer)
	: Io::Utility::Connection::ConnectionHelper(iec101InternalOrganizer.GetIoService(), iec101InternalOrganizer.GetMutex()),
	m_iec101Organizer(iec101Organizer), m_iec101InternalOrganizer(iec101InternalOrganizer), m_physicalLayer(std::move(physicalLayer))
{
}

void Iec101::Physical::PhysicalLayerInternal::Start(std::unique_ptr<Io::Utility::Connection::ConnectionSettings>&& connectionSettings, 
	std::unique_ptr<PhysicalLayerSetting>&& layerSetting)
{
	Io::Utility::Connection::ConnectionHelper::Start(std::move(connectionSettings));

	m_physicalLayerSetting = std::move(layerSetting);
}

void Iec101::Physical::PhysicalLayerInternal::AddLog(std::string && content)
{
}

bool Iec101::Physical::PhysicalLayerInternal::NeedFullIdentityLog()
{
	return false;
}

std::string Iec101::Physical::PhysicalLayerInternal::GetObjectIsStartedLog()
{
	return IO_FORMAT_LAYER0_INFOR "Physical layer is started";
}

std::string Iec101::Physical::PhysicalLayerInternal::GetObjectIsStoppedLog()
{
	return IO_FORMAT_LAYER0_INFOR "Physical layer is stopped";
}
