// Embeds core.h in a namespace and does nothing else

#pragma once

namespace lightbounce_lib {
	extern "C" {
		#include "core.h"
	}
}