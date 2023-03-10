#include "Particle.h"
#include <cstddef>
#include <cassert>

std::vector<StructProperty> const &Particle::GetProperties()
{
	static std::vector<StructProperty> properties = {
		{ "type"   , StructProperty::ParticleType, (intptr_t)(offsetof(Particle, type   )) },
		{ "life"   , StructProperty::Integer     , (intptr_t)(offsetof(Particle, life   )) },
		{ "ctype"  , StructProperty::ParticleType, (intptr_t)(offsetof(Particle, ctype  )) },
		{ "x"      , StructProperty::Float       , (intptr_t)(offsetof(Particle, x      )) },
		{ "y"      , StructProperty::Float       , (intptr_t)(offsetof(Particle, y      )) },
		{ "vx"     , StructProperty::Float       , (intptr_t)(offsetof(Particle, vx     )) },
		{ "vy"     , StructProperty::Float       , (intptr_t)(offsetof(Particle, vy     )) },
		{ "temp"   , StructProperty::Float       , (intptr_t)(offsetof(Particle, temp   )) },
		{ "flags"  , StructProperty::UInteger    , (intptr_t)(offsetof(Particle, flags  )) },
		{ "tmp"    , StructProperty::Integer     , (intptr_t)(offsetof(Particle, tmp    )) },
		{ "tmp2"   , StructProperty::Integer     , (intptr_t)(offsetof(Particle, tmp2   )) },
		{ "tmp3"   , StructProperty::Integer     , (intptr_t)(offsetof(Particle, tmp3   )) },
		{ "tmp4"   , StructProperty::Integer     , (intptr_t)(offsetof(Particle, tmp4   )) },
		{ "dcolour", StructProperty::UInteger    , (intptr_t)(offsetof(Particle, dcolour)) },
	};
	return properties;
}

std::vector<StructPropertyAlias> const &Particle::GetPropertyAliases()
{
	static std::vector<StructPropertyAlias> aliases = {
		{ "pavg0" , "tmp3"    },
		{ "pavg1" , "tmp4"    },
		{ "dcolor", "dcolour" },
	};
	return aliases;
}

std::vector<unsigned int> const &Particle::PossiblyCarriesType()
{
	struct DoOnce
	{
		std::vector<unsigned int> indices = {
			FIELD_LIFE,
			FIELD_CTYPE,
			FIELD_TMP,
			FIELD_TMP2,
			FIELD_TMP3,
			FIELD_TMP4,
		};

		DoOnce()
		{
			auto &properties = GetProperties();
			for (auto index : indices)
			{
				// code that depends on PossiblyCarriesType only knows how to set ints
				assert(properties[index].Type == StructProperty::Integer ||
				       properties[index].Type == StructProperty::ParticleType);
			}
		}
	};
	static DoOnce doOnce;
	return doOnce.indices;
}
