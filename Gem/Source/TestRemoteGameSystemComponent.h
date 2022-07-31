
#pragma once

#include <AzCore/Component/Component.h>

#include <TestRemoteGame/TestRemoteGameBus.h>

namespace TestRemoteGame
{
    class TestRemoteGameSystemComponent
        : public AZ::Component
        , protected TestRemoteGameRequestBus::Handler
    {
    public:
        AZ_COMPONENT(TestRemoteGameSystemComponent, "{ed470edd-62a0-416b-8372-c587275c8b11}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        TestRemoteGameSystemComponent();
        ~TestRemoteGameSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // TestRemoteGameRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
