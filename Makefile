VERSION = 1.0

UGLY = uglifyjs
CRUSH = pngcrush

ASSETS_DIR = _assets

IMG_FILES = $(wildcard $(ASSETS_DIR)/*.png)
IMG_TARGETS = $(addprefix img/, $(notdir $(IMG_FILES)))

convert: convert-png

convert-png: $(IMG_FILES) $(IMG_TARGETS)

$(IMG_TARGETS): $(IMG_FILES)
	@echo $^