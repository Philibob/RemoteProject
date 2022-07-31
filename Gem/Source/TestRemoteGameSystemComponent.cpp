
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "TestRemoteGameSystemComponent.h"

namespace TestRemoteGame
{
    void TestRemoteGameSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<TestRemoteGameSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<TestRemoteGameSystemComponent>("TestRemoteGame", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void TestRemoteGameSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("TestRemoteGameService"));
    }

    void TestRemoteGameSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("TestRemoteGameService"));
    }

    void TestRemoteGameSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void TestRemoteGameSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    TestRemoteGameSystemComponent::TestRemoteGameSystemComponent()
    {
        if (TestRemoteGameInterface::Get() == nullptr)
        {
            TestRemoteGameInterface::Register(this);
        }
    }

    TestRemoteGameSystemComponent::~TestRemoteGameSystemComponent()
    {
        if (TestRemoteGameInterface::Get() == this)
        {
            TestRemoteGameInterface::Unregister(this);
        }
    }

    void TestRemoteGameSystemComponent::Init()
    {
    }

    void TestRemoteGameSystemComponent::Activate()
    {
        TestRemoteGameRequestBus::Handler::BusConnect();
    }

    void TestRemoteGameSystemComponent::Deactivate()
    {
        TestRemoteGameRequestBus::Handler::BusDisconnect();
    }
}
