#include <mutex>

#include <Physical/PhysicalLayer.h>

#include <Physical/PhysicalLayerInternal.h>

Iec101::Physical::PhysicalLayer::PhysicalLayer()
{
	m_physicalLayerInternal = nullptr;
}

void Iec101::Physical::PhysicalLayer::Start(std::unique_ptr<Io::Utility::Connection::ConnectionSettings>&& connectionSettings, 
	std::unique_ptr<PhysicalLayerSetting>&& layerSetting)
{
	std::lock_guard<std::mutex> lock(m_physicalLayerInternal->GetMutex());
	m_physicalLayerInternal->Start(std::move(connectionSettings), std::move(layerSetting));
}

void Iec101::Physical::PhysicalLayer::SetInternalLayer(PhysicalLayerInternal * physicalInternalLayer)
{
	m_physicalLayerInternal = physicalInternalLayer;
}
