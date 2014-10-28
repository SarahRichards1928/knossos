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
</article>
</section>
{% endfor %}
</div>

<h1 data-scroll-index="11">Contact</h1>
If there are any questions, suggestions or other things you want to tell us, feel free to contact us using this address:

<a class="button" href="mailto:knossos-team@mpimf-heidelberg.mpg.de">knossos-team@mpimf-heidelberg.mpg.de</a>
