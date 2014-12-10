---
layout: page
title: About us
permalink: /about/
---

<div class="row">
<div class="col-md-12">
About us
========
**Knossos** is developed by a group of students from *Heidelberg University* and *Mannheim University of Applied Sciences*, employed at *Max Planck Institute for Medical Research*.
</div>
</div>

<div class="row">
{% for member in site.data.members %}
<div class="col-md-4 text-center">
<div class="avatar">
<img src="{{ site.baseurl }}/img/team/{{ member.picture }}">
</div>
<h2>{{ member.name }}</h2>
<p>{{ member.description }}</p>
</div>
{% endfor %}
</div>

<div class="row">
<div class="col-md-8 col-md-offset-2 text-center">
Contact us
==========
If you have any questions or suggestions regarding **Knossos**, feel free to write us:

<a class="button button-primary" href="mailto:knossos-team@mpimf-heidelberg.mpg.de">{% include fa.html icon="fa-envelope" %} <span>knossos-team@mpimf-heidelberg.mpg.de</span></a>
</div>
</div>