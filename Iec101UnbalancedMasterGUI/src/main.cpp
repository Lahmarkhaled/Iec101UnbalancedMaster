#include <iostream>

#include <IoUtility/Organizer/IoOrganizer.h>
#include <IoUtility/Connection/ConnectionSettings.h>
#include <Iec101OrganizerGUI.h>
#include <PhysicalLayerGUI.h>
#include <Physical/PhysicalLayerSetting.h>


using namespace Io::Utility::Connection;
using namespace Iec101;
using namespace Iec101::Physical;

std::shared_ptr<Io::Organizer::IoOrganizer> ioOrganizer;

Iec101OrganizerGUI* iec101OrganizerGUI;
PhysicalLayerGUI* physicalLayerGUI;

void Init();

void AddPhysicalLayer();
void StartPhysicalLayer();

int main()
{
	Init();

	AddPhysicalLayer();

	StartPhysicalLayer();

	std::cout << "Press enter to continue" << std::endl;
	std::cin.ignore();

}

void Init()
{
	ioOrganizer = std::make_shared<Io::Organizer::IoOrganizer>();
	ioOrganizer->Start();

	std::unique_ptr<Iec101OrganizerGUI> _org = std::make_unique<Iec101OrganizerGUI>();

	iec101OrganizerGUI = _org.get();
	ioOrganizer->AddSubOrgaizer(std::move(_org));
}

void AddPhysicalLayer()
{
	auto layerGUI = std::make_unique<PhysicalLayerGUI>();

	physicalLayerGUI = layerGUI.get();

	iec101OrganizerGUI->AddPhysicalLayer(std::move(layerGUI));
}

void StartPhysicalLayer()
{
	std::vector<TcpEndPoint> tcpClientEndpoints;
	tcpClientEndpoints.emplace_back(TcpEndPoint("127.0.0.1", 2404, 0, 0));

	std::unique_ptr<TcpClientSettings> tcpClientSettings(new TcpClientSettings(std::move(tcpClientEndpoints)));
	tcpClientSettings->SetCircularMode();

	std::unique_ptr<ConnectionSettings> connectionSettings(new ConnectionSettings(std::move(tcpClientSettings)));

	//
	std::unique_ptr<PhysicalLayerSetting> layerSetting(new (PhysicalLayerSetting)(1));

	physicalLayerGUI->Start(std::move(connectionSettings), std::move(layerSetting));
}
