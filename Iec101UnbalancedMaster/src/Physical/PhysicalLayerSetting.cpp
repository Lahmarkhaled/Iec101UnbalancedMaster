#include <Physical/PhysicalLayerSetting.h>

Iec101::Physical::PhysicalLayerSetting::PhysicalLayerSetting(uint8_t addressSize)
	: m_addressSize(addressSize)
{
}

uint8_t Iec101::Physical::PhysicalLayerSetting::GetAddressSize() const
{
	return m_addressSize;
}
