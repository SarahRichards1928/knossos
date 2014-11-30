---
layout: page
title: About us
permalink: /about/
---
About us
========
**Knossos** is developed by a group of students from *Heidelberg University* and *Mannheim University of Applied Sciences*, employed at *Max Planck Institute for Medical Research*.

{% for member in site.data.members %}
<section>
<div>
![{{ member.name }}]({{ site.baseurl }}/img/team/{{ member.picture }} "{{ member.name }}")
</div>

<div>
{{ member.name }}
-----------------
{{ member.description }}
</div>
</section>
{% endfor %}


Contact us
==========
If you have any questions or suggestions regarding **Knossos**, feel free to write us:

<a href="mailto:knossos-team@mpimf-heidelberg.mpg.de" class="button">{% include fa.html icon="fa-envelope" %} <span>knossos-team@mpimf-heidelberg.mpg.de</span></a>