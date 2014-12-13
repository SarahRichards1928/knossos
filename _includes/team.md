<div class="row">
<div class="twelve columns">

About us
========
**Knossos** is developed by a group of students from *Heidelberg University* and *Mannheim University of Applied Sciences*, employed at *Max Planck Institute for Medical Research*.

</div>
</div>

<div class="row">
<ul>
{% for member in site.data.members %}
<li>
<img src="{{ site.baseurl }}/img/team/{{ member.picture }}">
<h2>{{ member.name }}</h2>
<p>{{ member.description }}</p>
</li>
{% endfor %}
</ul>
</div>

<div class="row">
<div class="twelve columns">
Contact us
==========
If you have any questions or suggestions regarding **Knossos**, feel free to write us:

<a id="contact" class="button button-primary" href="mailto:knossos-team@mpimf-heidelberg.mpg.de">{% include fa.html icon="fa-envelope" %} knossos-team<span>@mpimf-heidelberg.mpg.de</span></a>
</div>
</div>