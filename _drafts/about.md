---
layout: page
title: About us
permalink: /about/
---
About us
========
**Knossos** is being developed at *Max Planck Institute for
Medical Research* located in *Heidelberg, Germany*.
The project leaders---Jörgen Kornfeld and Fabian Svara---are currently doing
their Ph.D. at MPI, while the rest of the team consists of students from
*Heidelberg University* and *Mannheim University of Applied Sciences.*

<div class="members">
{% for member in site.data.members %}
<section>
<aside>
<img src="{{ site.baseurl }}/img/{{ member.picture }}">
</aside>

<article>
{{ member.name }}
-----------------

* {{ member.description }}
* <i class=" fa fa-github"></i> [{{ member.github }}](https://github.com/{{ member.github}})
</article>
</section>
{% endfor %}
</div>

Contact
=======

Feel free to contact us if you have any questions about **Knossos**:

<!-- http://forms.brace.io -->
<form>
<p>
<label for="text_field">Your name:</label>
<input type="text" id="text_field" />
</p>

<p>
<label for="text_area">Your message:</label>
<textarea id="text_area"></textarea>
</p>

<p><input class="button" type="submit" value="Submit" /></p>
</form>

You can also write us using this e-mail address:
<a class="button" href="mailto:knossos-team@mpimf-heidelberg.mpg.de">knossos-team@mpimf-heidelberg.mpg.de</a>
