---
layout: page
title: The Team
permalink: /team/
---
**Knossos** is being developed at *Max Planck Institute for
Medical Research* located in *Heidelberg, Germany*.
The project leaders---Jörgen Kornfeld and Fabian Svara---are currently doing
their PhD at MPI, while the rest of the team consists of students from
*Heidelberg University* and *Mannheim University of Applied Sciences.*

* * *

{% for member in site.data.members %}
<div>
<aside>
<img src="{{ site.baseurl }}/img/{{ member.picture }}">
</aside>

<article>
{{ member.name }}
-----------------

{{ member.description }}

<i class=" fa fa-github"></i> [{{ member.github }}](https://github.com/{{ member.github}})
</article>
</div>
{% endfor %}

* * *

Feel free to contact us if you have any questions about **Knossos**:

<fieldset>
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
</fieldset>

You can also write us using this e-mail address:
<span class="button">[knossos-team@mpimf-heidelberg.mpg.de](mailto:knossos-team@mpimf-heidelberg.mpg.de)
