serve:
	jekyll serve --watch --baseurl ""

sync:
	browser-sync start --proxy localhost:4000 --files "css/*.css, *html"
