.. -*- rst -*-

=========
 Flavors
=========

Show and manage server flavors.

Flavors are a way to describe the basic dimensions of a server to be
created including how much ``cpu``, ``ram``, and ``disk space`` are
allocated to a server built with this flavor.

List Flavors
============

.. rest_method:: GET /v2.1/{tenant_id}/flavors

Lists all flavors accessible to your project.

Normal response codes: 200

Error response codes: unauthorized(401), forbidden(403)

Request
-------

.. rest_parameters:: parameters.yaml

  - tenant_id: tenant_id
  - sort_key: sort_key
  - sort_dir: sort_dir
  - limit: limit
  - marker: marker
  - minDisk: minDisk
  - minRam: minRam
  - is_public: flavor_is_public_query

Response
--------

.. rest_parameters:: parameters.yaml

   - flavors: flavors
   - id: flavor_id_body
   - name: flavor_name
   - links: links

**Example List Flavors**

Showing all the default flavors of a Liberty era Nova installation
that was not customized by the site operators.

.. literalinclude:: ../../doc/api_samples/flavors/flavors-list-resp.json
   :language: javascript

Create Flavor
=============

.. rest_method:: POST /v2.1/{tenant_id}/flavors

Creates a flavor.

Creating a flavor is typically only available to administrators of a
cloud because this has implications for scheduling efficiently in the cloud.

Normal response codes: 200

Error response codes: badRequest(400), unauthorized(401), forbidden(403),
conflict(409)

Request
-------

.. rest_parameters:: parameters.yaml

   - tenant_id: tenant_id
   - flavor: flavor
   - name: flavor_name
   - id: flavor_id_body
   - ram: flavor_ram
   - disk: flavor_disk
   - vcpus: flavor_cpus
   - OS-FLV-EXT-DATA:ephemeral: flavor_ephem_disk_in
   - swap: flavor_swap_in
   - rxtx_factor: flavor_rxtx_factor_in
   - os-flavor-access:is_public: flavor_is_public_in

**Example Create Flavor**

.. literalinclude:: ../../doc/api_samples/flavor-manage/flavor-create-post-req.json
   :language: javascript

Response
--------

.. rest_parameters:: parameters.yaml

   - tenant_id: tenant_id
   - flavor: flavor
   - name: flavor_name
   - id: flavor_id_body
   - ram: flavor_ram
   - disk: flavor_disk
   - vcpus: flavor_cpus
   - links: links
   - OS-FLV-EXT-DATA:ephemeral: flavor_ephem_disk
   - OS-FLV-DISABLED:disabled: flavor_disabled
   - swap: flavor_swap
   - rxtx_factor: flavor_rxtx_factor
   - os-flavor-access:is_public: flavor_is_public


**Example Create Flavor**

.. literalinclude:: ../../doc/api_samples/flavor-manage/flavor-create-post-resp.json
   :language: javascript

List Flavors With Details
=========================

.. rest_method:: GET /v2.1/{tenant_id}/flavors/detail

Lists flavors with details.

Normal response codes: 200

Error response codes: badRequest(400), unauthorized(401), forbidden(403)

Request
-------

.. rest_parameters:: parameters.yaml

  - tenant_id: tenant_id
  - sort_key: sort_key
  - sort_dir: sort_dir
  - limit: limit
  - marker: marker
  - minDisk: minDisk
  - minRam: minRam
  - is_public: flavor_is_public_query


Response
--------

.. rest_parameters:: parameters.yaml

   - tenant_id: tenant_id
   - flavors: flavors
   - name: flavor_name
   - id: flavor_id_body
   - ram: flavor_ram
   - disk: flavor_disk
   - vcpus: flavor_cpus
   - links: links
   - OS-FLV-EXT-DATA:ephemeral: flavor_ephem_disk
   - OS-FLV-DISABLED:disabled: flavor_disabled
   - swap: flavor_swap
   - rxtx_factor: flavor_rxtx_factor
   - os-flavor-access:is_public: flavor_is_public

**Example List Flavors With Details**

.. literalinclude:: ../../doc/api_samples/flavors/flavors-detail-resp.json
   :language: javascript

Show Flavor Details
===================

.. rest_method:: GET /v2.1/{tenant_id}/flavors/{flavor_id}

Shows details for a flavor.

Normal response codes: 200

Error response codes: unauthorized(401), forbidden(403), itemNotFound(404)

Request
-------

.. rest_parameters:: parameters.yaml

  - tenant_id: tenant_id
  - flavor_id: flavor_id

Response
--------

.. rest_parameters:: parameters.yaml

   - tenant_id: tenant_id
   - flavor: flavor
   - name: flavor_name
   - id: flavor_id_body
   - ram: flavor_ram
   - disk: flavor_disk
   - vcpus: flavor_cpus
   - links: links
   - OS-FLV-EXT-DATA:ephemeral: flavor_ephem_disk
   - OS-FLV-DISABLED:disabled: flavor_disabled
   - swap: flavor_swap
   - rxtx_factor: flavor_rxtx_factor
   - os-flavor-access:is_public: flavor_is_public

**Example Show Flavor Details**

.. literalinclude:: ../../doc/api_samples/flavors/flavor-get-resp.json
   :language: javascript

Delete Flavor
=============

.. rest_method:: DELETE /v2.1/{tenant_id}/flavors/{flavor_id}

Deletes a flavor.

This is typically an admin only action. Deleting a flavor that is in use by
existing servers is not recommended as it can cause incorrect data to
be returned to the user under some operations.

Normal response codes: 202

Error response codes: unauthorized(401), forbidden(403), itemNotFound(404)

Request
-------

.. rest_parameters:: parameters.yaml

  - tenant_id: tenant_id
  - flavor_id: flavor_id

Response
--------

No body content is returned on a successful DELETE.
