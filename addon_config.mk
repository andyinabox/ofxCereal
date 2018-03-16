meta:
	ADDON_NAME = ofxCereal
	ADDON_DESCRIPTION = An openFrameworks wrapper for Cereal.
	ADDON_AUTHOR = Christopher Baker
	ADDON_TAGS = "serialization"
	ADDON_URL = http://github.com/bakercp/ofxCereal

common:
	# Exclude includes and source.
	ADDON_SOURCES_EXCLUDE = libs/cereal/include/%
	ADDON_INCLUDES_EXCLUDE = libs/cereal/include/%

	# Manually add the includes and source.
	ADDON_INCLUDES = libs/cereal/include
	ADDON_INCLUDES += libs/ofxCereal/include
	ADDON_INCLUDES += src

osx:
