<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<head>
  <title>CD Collection</title>
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css"/>

  <style>
    tr:first-child {
      background-color: red;
    }
  </style>


</head>
<body>
  
  <div class="row">

    <div class="col-md-12">
      <div class="col-md-4">
      </div>
      <div class="col-md-4">
        <h2>My CD Collection</h2>
      </div>
      <div class="col-md-4">
      </div>
    </div>

    <div class="col-md-11" style="margin-left: 4%;">
      <div class="col-md-4">
      </div>
      <div class="col-md-3">
        <table border="1">

            <th class="bg-info" style="text-align:left;">Country</th>
            <th class="bg-warning" style="text-align:left">Title</th>
            <th class="bg-info" style="text-align:left;">Artist</th>
            <th class="bg-info" style="text-align:left;">Company</th>
            <th class="bg-info" style="text-align:left;">Price</th>


          <xsl:for-each select="catalog/cd">
          <tr>

            <td class="bg-primary"><xsl:value-of select="country"/></td>

            <xsl:for-each select="band">

              <xsl:variable name="level1Position" select="position()"/>

              <td><xsl:value-of select="title"/></td>
              <td><xsl:value-of select="artist"/></td>

            </xsl:for-each>

            <td class="bg-primary"><xsl:value-of select="company"/></td>
            <td class="bg-primary"><xsl:value-of select="price"/></td>

          </tr>
          </xsl:for-each>


          


        </table>
      </div>
      <div class="col-md-4">
      </div>
    </div>
  </div>
</body>
</html>
</xsl:template>
</xsl:stylesheet>

