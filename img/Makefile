VERSION = 1.0

UGLY = uglifyjs
CRUSH = pngcrush

ASSETS_DIR = _assets
BOWER_DIR = bower_components
JS_DIR = js
IMG_DIR = img

JS_FILES = $(BOWER_DIR)/jquery/dist/jquery.min.js \
					 $(ASSETS_DIR)/scrollIt.min.js \
					 $(ASSETS_DIR)/main.js
# $(BOWER_DIR)/particleground/jquery.particleground.min.js \

PNG_FILES = $(wildcard $(ASSETS_DIR)/*.png)
JPG_FILES = $(wildcard $(ASSETS_DIR)/*.jpg)
GIF_FILES = $(wildcard $(ASSETS_DIR)/*.gif)
SVG_FILES = $(wildcard $(ASSETS_DIR)/*.svg)

.PHONY: js
js: $(JS_FILES)
	smash $^ > $(JS_DIR)/js.js

minify: $(JS_FILES)
	smash $^ | uglifyjs > $(JS_DIR)/js.min.js

# $(JS_DIR)/$(JS_MAIN).min.js: $(JS_FILES)

# png: $(subst $(ASSETS_DIR)/,$(IMG_DIR)/,$(PNG_FILES))
# jpg: $(subst $(ASSETS_DIR)/,$(IMG_DIR)/,$(JPG_FILES))
# gif: $(subst $(ASSETS_DIR)/,$(IMG_DIR)/,$(GIF_FILES))
# svg: $(subst $(ASSETS_DIR)/,$(IMG_DIR)/,$(SVG_FILES))

# $(IMG_DIR)/%.png: $(ASSETS_DIR)/%.png
# 	pngcrush -rem allb -brute -reduce $< $@

# $(IMG_DIR)/%.jpg: $(ASSETS_DIR)/%.jpg
# 	cp $< $@

# $(IMG_DIR)/%.gif: $(ASSETS_DIR)/%.gif
# 	cp $< $@

# $(IMG_DIR)/%.svg: $(ASSETS_DIR)/%.svg
# 	cp $< $@

# style:
# 	sass --scss --style compressed _sass/_layout.scss:_includes/style.html

