#include "RE/Bethesda/TESObjectREFRs.h"

#include "RE/NetImmerse/NiAVObject.h"

namespace RE
{
	BIPOBJECT::~BIPOBJECT()
	{
		Dtor();
		stl::memzero(this);
	}
	TESBoundObject* TESObjectREFR::GetBaseObject()
	{
		return data.objectReference;
	}
	const TESBoundObject* TESObjectREFR::GetBaseObject() const
	{
		return data.objectReference;
	}
	
	//ID Identification Test
	BGSLocation* TESObjectREFR::GetCurrentLocation() const
	{
		using func_t = decltype(&TESObjectREFR::GetCurrentLocation);
		REL::Relocation<func_t> func{ REL::ID(866309) };
		return func(this);
	}
}
