#import <Realm/Realm.h>

@interface RLMObject (JSONAPIURL)

/**
 * Turns the defaultAttributes and defaultRelationships of this object into
 * sparse fieldset and included resource query parameters,
 * and appends those query parameters to the provided string.
 * You should use this method (or JSONAPIURLUtilities, which this method uses under the hood)
 * on all of your API requests, as it allows your server to change its defaults without breaking clients.
 * By explicitly requesting what you want, you make the server not have to guess.
 *
 * @param bareURL The URL to which you wish to append the sparse fieldset and included resource query parameters
 *
 * @return An NSString created by joining the bare URL
 * with the sparse fieldset and included resource query parameters.
 *
 * @see [JSONAPIURLUtilities specifiedURLForBareURL:withIncludes:andFields:]
 * @see [http://jsonapi.org/format#fetching-includes](http://jsonapi.org/format#fetching-includes) JSON:API docs on Inclusion of Related Resources.
 * @see [http://jsonapi.org/format#fetching-sparse-fieldsets](http://jsonapi.org/format#fetching-sparse-fieldsets) JSON:API docs on Sparse Fieldsets
 */
+ (NSString *)defaultURLDecoration:(NSString *)bareURL;

/**
 * Useful if you wish to modify the query parameters instead of using the defaultURLDecoration method directly.
 *
 * @return This class's defaultAttributes NSArray as the value in a dictionary where this class's type is the key.
 */
+ (NSDictionary *)defaultAttributesAsFieldsDictionary;

/**
 * Useful if you wish to modify the query parameters instead of using the defaultURLDecoration method directly.
 *
 * @param relationships A list of the relationships for which you want to specify your desired fields.
 * Can be dot-separated paths, as per the JSON:API spec's discussion of include query parameter values.
 *
 * @return This class's defaultAttributes NSArray as the value in a dictionary where this class's type is the key,
 * along with each of the related class's defaultAttributes as values corresponding to their types as keys.
 */
+ (NSDictionary *)fieldsIncludingRelationships:(NSArray *)relationships;

@end
