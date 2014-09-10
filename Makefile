VERSION = 1.0

UGLY = uglifyjs
CRUSH = pngcrush

ASSETS_DIR = _assets
JS_DIR = js
IMG_DIR = img

PNG_FILES = $(wildcard $(ASSETS_DIR)/*.png)
JPG_FILES = $(wildcard $(ASSETS_DIR)/*.jpg)

JS_FILES = $(wildcard $(ASSETS_DIR)/*.js)
JS_MAIN = main

images: png jpg
minify: js

js: $(subst $(ASSETS_DIR)/,$(JS_DIR)/,$(JS_FILES:.js=.min.js))

$(JS_DIR)/$(JS_MAIN).min.js: $(JS_FILES)

png: $(subst $(ASSETS_DIR)/,$(IMG_DIR)/,$(PNG_FILES))
jpg: $(subst $(ASSETS_DIR)/,$(IMG_DIR)/,$(JPG))

$(IMG_DIR)/%.png: $(ASSETS_DIR)/%.png
	pngcrush -rem allb -brute -reduce $< $@


$(IMG_DIR)/%.jpg: $(ASSETS_DIR)/%.jpg
	cp $< $@

watch:
	osascript -e 'tell application "Safari"' -e 'set docUrl to URL of document 1' -e 'set URL of document 1 to docUrl' -e 'end tell'

clean:
	rm $(IMG_DIR)/*.png
	rm $(IMG_DIR)/*.jpg
