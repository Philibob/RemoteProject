
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "TestRemoteGameSystemComponent.h"

namespace TestRemoteGame
{
    class TestRemoteGameModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(TestRemoteGameModule, "{58a9cbf1-8d9a-4d9f-b435-54a28c1b0062}", AZ::Module);
        AZ_CLASS_ALLOCATOR(TestRemoteGameModule, AZ::SystemAllocator, 0);

        TestRemoteGameModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                TestRemoteGameSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<TestRemoteGameSystemComponent>(),
            };
        }
    };
}// namespace TestRemoteGame

AZ_DECLARE_MODULE_CLASS(Gem_TestRemoteGame, TestRemoteGame::TestRemoteGameModule)
